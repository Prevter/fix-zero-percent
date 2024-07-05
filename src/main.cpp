#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

class $modify(PlayLayer) {
	float customGetProgress() {
		float percent;
		if (m_level->m_timestamp > 0) {
			percent = static_cast<float>(m_gameState.m_levelTime * 240.f) / m_level->m_timestamp * 100.f;
		} else {
			percent = reinterpret_cast<cocos2d::CCNode*>(m_player1)->getPositionX() / m_levelLength * 100.f;
		}
		return std::clamp(percent, 0.f, 100.f);
	}

	void updateProgressbar() {
		PlayLayer::updateProgressbar();
		if (m_percentageLabel == nullptr) return;
		if (m_level->isPlatformer()) return;

		float percent = customGetProgress();
		auto numDigits = GameManager::get()->getGameVariable("0126") ? 2 : 0;
		m_percentageLabel->setString(fmt::format("{:.{}f}%", percent, numDigits).c_str());
		m_progressFill->setTextureRect({
			0, 0,
			(m_progressBar->getTextureRect().getMaxX() - 5) * percent / 100.f,
			m_progressBar->getTextureRect().getMaxY() / 2
		});
	}
};